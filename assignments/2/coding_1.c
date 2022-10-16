//
// Created by haoyu on 9/18/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct string {
    char *s;
    int len, cap;
} String;


String *append_string(String *s, char c) {
    if (s->cap == s->len) {
        s->cap <<= 1;
        s->s = (char *) realloc(s->s, s->cap);
    }
    s->s[s->len++] = c;
    s->s[s->len] = 0;
    return s;
}

char *getLine(String *s) {
    s->len = 0;
    char c;
    while (1) {
        c = getchar();
        if (c == -1 || c == '\n') return s->s;
        append_string(s, c);
    }
}

#define YES  "YES"
#define NO  "NO"

char *solution(int D, int C, int M, char *S) {
    
    /*Complete this function*/
    int test = scanf("%d",&test);
    for(int t=1; t<=test; t++) {
        
        int d = scanf("%d",&D);
        int n = scanf("%d",&n);
        int c = scanf("%d",&C);
        int m = scanf("%d",&M);
        
       String s;
       char cd[10];
       bool feed = true;

       for(int i=0; i<n; i++) {
           if(cd[i] == 'C') {
               if(c <= 0) {
                   while(i < n) {
                       if(cd[i] == 'D') feed = false;
                       i++;
                   }
                   break;
               }
               C--;
           }
           if(cd[i] == 'D') {
               if(d <= 0) {
                   feed = false;
                   break;
               }
               D--;
               C += M;
           }
       }

        printf("Case #%d: %s\n",t,feed == true ? "YES" : "NO");
    }
    return YES;

}

int main(int argc, char *argv[]) {
    int t, D, C, M, L;
    String s1 = {malloc(10), 0, 10},
            s2 = {malloc(10), 0, 10};
    t = atoi(getLine(&s1));
    for (int i = 1; i <= t; ++i) {
        getLine(&s1);
        getLine(&s2);
        sscanf(s1.s, "%d %d %d %d", &L, &D, &C, &M);
        if (argc == 1) {
            printf("Case #%d: %s\n", i, solution(D, C, M, s2.s));
        } else if (atoi(argv[1]) == i) {
            printf("s1: %s\n", s1.s);
            printf("s2: %s\n", s2.s);
        }
        s1.len = 0;
        s2.len = 0;
    }
    return 0;
}
