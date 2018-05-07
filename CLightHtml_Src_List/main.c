#include <stdio.h>
#include <string.h>
#include <ctype.h>


void clearCharBuff(char[]);
char* validTag(char HtmlLoad[]);
void countSrc(char[]);
void tagSrc(char[]);
void urlSrc(char[]);
void freqSrc(char[]);

enum Tags {AUDIO, EMBED, IFRAME, IMG, INPUT, SCRIPT, SOURCE, TRACK, VIDEO};


int main() {
    // Turn off output buffering. Required for automated testing:
    //setvbuf(stdout, NULL, _IONBF, 0);

    printf("URL:\n");
    char Uin [BUFSIZ];
    fgets(Uin, BUFSIZ, stdin);
    Uin[strlen(Uin)-1]= '\0';
    char Curlcmd[BUFSIZ] = "curl -s ";
    strcat( Curlcmd, Uin);
    //printf(Curlcmd);

    char HtmlLoad[256000];
    FILE *fp;
    fp = popen(Curlcmd, "r");
    while(!feof(fp)){
        char HtmlLoadConcat[128000];
        fgets(HtmlLoadConcat,128000, fp);
        strcat(HtmlLoad, HtmlLoadConcat);
    }
    //printf(HtmlLoad);
    pclose(fp);

    //printf("%d",strlen(Uin));
    clearCharBuff(Uin);
    do {
        printf("Ready \n");
        scanf("%s", Uin);
        switch (Uin[0]){
            case 'c':
                //printf("c chosen\n");
                countSrc(HtmlLoad);
                break;
            case 't':
                //printf("t chosen\n");
                tagSrc(HtmlLoad);
                break;
            case 'u':
                //printf("u chosen\n");
                urlSrc(HtmlLoad);
                break;
            case 'f':
                //printf("f chosen\n");
                freqSrc(HtmlLoad);
                break;
            case 'q':
                break;
            default:
                printf("not a valid choice\n");
                break;
        }
    }while (Uin[0]!='q');
    printf("Complete");

    return 0;
}

void clearCharBuff(char CharBuff[]){
    int clearCBLen = strlen(CharBuff);
    for(int i = 0;i<=clearCBLen;i++)
        CharBuff[i]='\0';
}

char * validTag(char *pIn){
    char srcKey[] = "src=\"";
    char *pSrc = strstr(pIn, srcKey);
    if (pSrc != NULL)
        while (!isspace(*(pSrc - 1))) {
            pSrc++;
            pSrc = strstr(pSrc, srcKey);
        }
    return(pSrc);
}

void countSrc(char HtmlLoad[]) {
    char *pSrc = validTag(HtmlLoad);
    int countSrc = 0;
    while (pSrc) {
        countSrc++;
        pSrc++;
        pSrc = validTag(pSrc);
    }
    printf("%d \n", countSrc);
}

void tagSrc(char HtmlLoad[]) {
    char *pSrc = validTag(HtmlLoad);
    char *pT;

    while (pSrc != NULL) {
        pT = pSrc;
        while (*pT != '<') {
            pT--;
        }
        pT++;
        while (*pT != ' ' && *pT != '\n' && *pT != '\f' && *pT != '\r' && *pT != '\t' && *pT != '\v') {
            printf("%c", *pT);
            pT++;
        }
        printf("\n");
        pSrc++;
        pSrc = validTag(pSrc);
    }
}

void urlSrc(char HtmlLoad[]){
    char *pSrc = validTag(HtmlLoad);
    char srcURL[BUFSIZ];
    char *pQ;

    while (pSrc != NULL) {
        pQ = pSrc + 5;
        while(*pQ != '\"'){
            strncat(srcURL,pQ,1);
            pQ++;
        }
        printf("%s \n", srcURL);
        clearCharBuff(srcURL);
        pSrc++;
        pSrc = validTag(pSrc);
    }
}
void freqSrc(char HtmlLoad[]){
    int Counts[9][4] = {{0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0}};
    const char TagIndex[9][7] = {"audio", "embed", "iframe", "img", "input", "script", "source", "track", "video"};

    char *pSrc = validTag(HtmlLoad);
    char *pT;
    int passCount = 1;

    while(pSrc){
        pT = pSrc;
        while (*pT != '<') {
            pT--;
        }
        pT++;
        enum Tags tag = AUDIO;
        for (tag; tag <= VIDEO; tag++){
            if (strncmp(pT,TagIndex[tag],strlen(TagIndex[tag])) == 0) {
                Counts[tag][2]++;
                if(Counts[tag][3] != 1)
                    Counts[tag][1] = passCount;
                Counts[tag][3]=1;
            }
        }

        passCount++;
        pSrc++;
        pSrc = validTag(pSrc);
    }

    int minPassCount = 1, notDone = 1;
    while ( notDone ) {
        notDone--;
        for (size_t i = 0; i <= 8; i++) {
            if (Counts[i][1] != 0)
                notDone++;
        }
        for (size_t i = 0; i <= 8; i++) {
            if (Counts[i][1] > 0 && Counts[i][1] <= minPassCount && Counts[i][2] != 0) {
                printf("%s \t %d \n", TagIndex[i], Counts[i][2]);
                Counts[i][1] = 0;
                notDone--;
            }
        }
        minPassCount++;
    }
}