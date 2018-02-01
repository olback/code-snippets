/**
 *  2018 © olback.net
 *  https://github.com/olback/code-snippets/tree/master/c/file-content-clipboard
 */

#include <stdio.h>
#include <windows.h>
#include <lmcons.h>

int main(int argc, char *argv[])
{
    /* What file should the program look for in `%appdata%\Roaming`? */
    const char filename[] = "clipData.txt";

    /* Get username */
    char username[UNLEN+1];
    DWORD uLen = sizeof(username);
    GetUserName(username, &uLen);

    /* Construct file path */
    char path[MAX_PATH];
    if(argv[1])
        sprintf(path, "%s", argv[1]);
    else
        sprintf(path, "C:\\Users\\%s\\AppData\\Roaming\\%s", username, filename);

    /* Read data from file */
    FILE *fp = fopen(path, "rb");
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(fsize + 1);
    fread(data, fsize, 1, fp);
    fclose(fp);

    data[fsize] = 0;

    /* Set clipboard data */
    const size_t len = strlen(data) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), data, len);
    GlobalUnlock(hMem);

    if(!OpenClipboard(0))
        printf("Failed to open clipboard.\n");

    if(!EmptyClipboard())
        printf("Failed to empty clipboard\n");

    if(SetClipboardData(CF_TEXT, hMem))
        printf("Set clipboard data to:\n%s", data);
    else
        printf("Failed to set clipboard data.\n");

    if(!CloseClipboard())
        printf("Failed to close clipboard.\n");

    return 0;
}
