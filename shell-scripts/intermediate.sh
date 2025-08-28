#!/usr/bin/env bash
set -euo pipefail

read -r -p "Enter a number: " NUM
if (( NUM > 10 )); then
  echo "Greater than 10"
else
  echo "10 or less"
fi

for i in {1..5}; do
  echo "Iteration $i"
done

greet() {
  echo "Hello from function!"
}
greet
#!/user/bin/env bash 

read -p "enter a number: " NUM 
 if [ "$UM" -gt 10 ]; then 
    echo "Greater than 10" 
else  
    echo "10 or less" 
fi 

for i in  {1..5}; do 
    echo  "Iteration $i"
done 

greet()  { 
echo " Hello from function!"
} 
greet 
