#include<stdio.h>
#include<stdlib.h>
void read(char *s)
{
  gets(s);
}
void strcopy(char *s1,char *s2)
{
  int i;
  for(i = 0;s2[i];i++)
  {
    s1[i] = s2[i];
  }
  s1[i] = '\0';
}
int matchnreplace(char *str,char *pat,char *rep)
{
  char ans[100];
  int i = 0,m = 0,c = 0,j = 0,flag = 0,k = 0;
  while(str[c]!='\0')
  {
    if(str[m] == pat[i])
    {
      m++;
      i++;
      if(pat[i] == '\0')
      {
        flag = 1;
        for(k = 0;rep[k]!='\0';k++,j++)
        {
          ans[j] = rep[k];
        }
        i = 0;
        c = m;
      }
    }
    else
    {
      ans[j] = str[c];
      j++;c++;m = c;i = 0;
    }
  }
  ans[j] = '\0';
  strcopy(str,ans);
  return flag;
}
int main()
{
  char str[100],pat[20],rep[20];
  int flag = 0;
  printf("Enter the string");
  read(str);
  printf("Enter the pattern");
  read(pat);
  printf("\nEnter the rep");
  read(rep);
  flag = matchnreplace(str,pat,rep);
  if(flag == 1)
  {
    printf("\nThe string is %s",str);
  }
  else
  {
    printf("\nString did not match");
    return 0;
  }
  return 0;
}
