#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DB_FILE "contacts.txt"

struct Contact {
    char name[64];
    int  age;
    char phone[32];
};

static void usage(const char *prog){
    fprintf(stderr,
      "Usage:\n"
      "  %s add \"Name With Spaces\" <age> <phone>\n"
      "  %s view\n", prog, prog);
}

static int save_contact(const struct Contact *c){
    FILE *fp = fopen(DB_FILE, "a");
    if(!fp){ perror("fopen"); return 1; }
    // CSV line: name,age,phone
    fprintf(fp, "%s,%d,%s\n", c->name, c->age, c->phone);
    fclose(fp);
    return 0;
}

static int view_contacts(void){
    FILE *fp = fopen(DB_FILE, "r");
    if(!fp){
        perror("fopen");
        fprintf(stderr, "No contacts yet. (%s will be created on first add)\n", DB_FILE);
        return 1;
    }
    char line[256];
    int n = 0;
    printf("---- Contacts ----\n");
    while(fgets(line, sizeof line, fp)){
        // parse CSV
        struct Contact c;
        char *name = strtok(line, ",");
        char *age  = strtok(NULL, ",");
        char *ph   = strtok(NULL, ",\n");
        if(!name || !age || !ph) continue;
        strncpy(c.name, name, sizeof c.name);
        c.name[sizeof c.name - 1] = '\0';
        c.age = atoi(age);
        strncpy(c.phone, ph, sizeof c.phone);
        c.phone[sizeof c.phone - 1] = '\0';
        printf("%2d) %-20s  Age: %-3d  Phone: %s\n", ++n, c.name, c.age, c.phone);
    }
    if(n == 0) printf("(empty)\n");
    fclose(fp);
    return 0;
}

int main(int argc, char **argv){
    if(argc < 2){ usage(argv[0]); return 1; }

    if(strcmp(argv[1], "add") == 0){
        if(argc != 5){ usage(argv[0]); return 1; }
        struct Contact c;
        // argv[2] must be quoted if it has spaces
        strncpy(c.name, argv[2], sizeof c.name);
        c.name[sizeof c.name - 1] = '\0';

        // validate age is digits
        for(char *p = argv[3]; *p; ++p){
            if(!isdigit((unsigned char)*p)){
                fprintf(stderr, "Age must be a positive integer.\n");
                return 1;
            }
        }
        c.age = atoi(argv[3]);

        strncpy(c.phone, argv[4], sizeof c.phone);
        c.phone[sizeof c.phone - 1] = '\0';

        if(save_contact(&c) == 0){
            printf("Added: %s, %d, %s\n", c.name, c.age, c.phone);
        }
        return 0;

    } else if(strcmp(argv[1], "view") == 0){
        return view_contacts();
    } else {
        usage(argv[0]);
        return 1;
    }
}
