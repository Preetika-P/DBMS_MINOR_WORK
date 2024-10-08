#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILENAME "Example.txt"
#define CONTENT "DBMS MINOR WORK HERE.\n"
#define BUFFER_SIZE 100

void createAndWriteFile() {
    int fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644); 
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    if (write(fd, CONTENT, strlen(CONTENT)) == -1) { 
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd); 
    printf("Content written to %s successfully.\n", FILENAME);
}

void readFile() {
    char buffer[BUFFER_SIZE];
    int fd = open(FILENAME, O_RDONLY); 
    if (fd == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("Error using lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1); 
    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0';
    printf("Content read from %s: %s", FILENAME, buffer);
    
    close(fd); 
}

int main() {
    createAndWriteFile(); 
    readFile();           
    if (unlink(FILENAME) == -1) {
        perror("Error removing file");
    } else {
        printf("File %s removed successfully.\n", FILENAME);
    }

    return 0;
}
