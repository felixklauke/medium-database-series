#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    /**
     * Obtaining the file descriptor to the demonstration file with create flag.
     */
    int fileDescriptor = open("testFile.bin", O_RDONLY | O_CREAT);

    /**
     * Creating buffer for the data we will read.
     */
    char buffer[4];

    /**
     * Reading the data of 4 bytes from the file descriptor beginning at index 0 into the buffer.
     */
    ssize_t bytesRead = pread(fileDescriptor, buffer, 4, 0);

    printf("Bytes read: %d\n", (int) bytesRead);

    /**
     * Print out the result.
     */
    printf("%d, %d, %d, %d", buffer[0], buffer[1], buffer[2], buffer[3]);

    close(fileDescriptor);
}