#ifndef UTILS_H
#define UTILS_H

void readLine(char *buffer, int size);
int readInt(const char *prompt);
int readPositiveInt(const char *prompt);
float readNonNegativeFloat(const char *prompt);
void readNonEmptyString(const char *prompt, char *buffer, int size);
void pauseScreen(void);

#endif
