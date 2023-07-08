#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <syslog.h>

int main() {
    // Open syslog with desired options
    openlog("CinnamonChecker", LOG_PID | LOG_CONS, LOG_USER);

    // Command to check if Cinnamon is running
    const char *command = "pgrep -x cinnamon";

    // Execute the command and get the output
    FILE *fp = popen(command, "r");
    char output[16];
    fgets(output, sizeof(output), fp);

    // Remove non-numeric characters from the output
    for (int i = 0; i < strlen(output); i++) {
        if (!isdigit(output[i])) {
            output[i] = '\0';
            break;
        }
    }

    // Check if the output is empty (Cinnamon is not running)
    if (strlen(output) == 0) {
        syslog(LOG_INFO, "Cinnamon is not running. Restarting...");

        // Command to restart Cinnamon
        const char *restartCommand = "cinnamon --replace &";

        // Execute the command to restart Cinnamon
        system(restartCommand);

        syslog(LOG_INFO, "Cinnamon restarted.");
    } else {
        syslog(LOG_INFO, "Cinnamon is running (PID: %s).", output);
    }

    // Close the file stream
    pclose(fp);

    // Close syslog
    closelog();

    return 0;
}
