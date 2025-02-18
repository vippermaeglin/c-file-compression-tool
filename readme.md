# INSTRUCTIONS TO RUN
1) cd into 'src' folder
2) run compile commands for each class
   * gcc -c utils.c
   * gcc -c compress.c
   * gcc -c decompress.c
   * gcc -c main.c
3) create executable file
   * gcc -o rle.exe main.o compress.o decompress.o utils.o  
4) run the compress command
   * ./rle.exe -c test_files/test.txt  
4) run the decompress command
   * ./rle.exe -d test_files/test.rle  