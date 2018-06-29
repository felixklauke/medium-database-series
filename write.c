#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    /**
     * Obtaining the file descriptor to the demonstration file with create flag.
     */
    int fileDescriptor = open("testFile.bin", O_WRONLY | O_CREAT);

    /**
     * Creating and filling a buffer with data.
     */
    char buffer[4];
    buffer[0] = 127;
    buffer[1] = 56;
    buffer[2] = 56;
    buffer[3] = 1;

    /**
     * Writing 4 bytes of the buffer to the file descriptor beginning at the index 0.
     */
    ssize_t bytesWritten = pwrite(fileDescriptor, buffer, 4, 0);

    printf("Bytes written: %d", (int) bytesWritten);

    /**
     * Close the file.
     */
    close(fileDescriptor);
}