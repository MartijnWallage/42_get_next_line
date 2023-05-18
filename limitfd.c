#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
    struct 	rlimit rlim;
	int		openfiles;
	int		fdopen[20];
	char	*baseName = "test";
	char	fileName[20];

	openfiles = 0;
	while (openfiles < RLIMIT_NOFILE)
	{
		snprintf(fileName, sizeof(fileName), "%s%d.txt", baseName, openfiles);
		fdopen[openfiles] = open(fileName, O_RDONLY | O_CREAT, 0644);
		printf("Opening file %d\n", fdopen[openfiles]);
		openfiles++;
	}
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        int max_fd = -1;
        for (int fd = 0; fd < rlim.rlim_cur; fd++) {
            if (fcntl(fd, F_GETFD) != -1) {
                max_fd = fd;  // Found an open file descriptor
            }
        }
        printf("RLIMIT_NOFILE: %d\nHighest open file descriptor: %d\n", RLIMIT_NOFILE, max_fd);
    } else {
        perror("getrlimit");
        return 1;
    }

    return 0;
}
