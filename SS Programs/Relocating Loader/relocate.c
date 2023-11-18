#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void convert(char h[12]);
char bitmask[12];
char bit[12] = {
  0
};
void main() {
  char add[6], length[10], input[10], binary[12], relocbit, ch, pn[5];
  int start, inp, len, i, address, opcode, addr, actualadd, tlen;
  FILE * fp1, * fp2;

  printf("\n\n Enter the actual starting address : ");
  scanf("%x", & start);
  fp1 = fopen("RLIN.txt", "r");
  fp2 = fopen("RLOUT.txt", "w");
  fscanf(fp1, "%s", input);
  fprintf(fp2, " ----------------------------\n");
  fprintf(fp2, " ADDRESS\tCONTENT\n");
  fprintf(fp2, " ----------------------------\n");
  while (strcmp(input, "E") != 0) {
    if (strcmp(input, "H") == 0) {
      fscanf(fp1, "%s", pn);
      fscanf(fp1, "%s", add);
      fscanf(fp1, "%s", length);
      fscanf(fp1, "%s", input);
    }
    if (strcmp(input, "T") == 0) {
      fscanf(fp1, "%x", & address);
      fscanf(fp1, "%x", & tlen);
      fscanf(fp1, "%s", bitmask);
      address += start;
      convert(bitmask);
      len = strlen(bit);
      if (len >= 11)
        len = 10;
      for (i = 0; i < len; i++) {
        fscanf(fp1, "%x", & opcode);
        fscanf(fp1, "%x", & addr);
        relocbit = bit[i];
        if (relocbit == '0')
          actualadd = addr;
        else
          actualadd = addr + start;
        fprintf(fp2, "%x\t\t%x%x\n", address, opcode, actualadd);
        address += 3;
      }
      fscanf(fp1, "%s", input);
    }
  }
  fprintf(fp2, "\n----------------------------\n");
  fcloseall();
  printf("\n\n The contents of output file(RLOUT.TXT) \n");
  fp2 = fopen("RLOUT.txt", "r");
  ch = fgetc(fp2);
  while (ch != EOF) {
    printf("%c", ch);
    ch = fgetc(fp2);
  }
  fclose(fp2);

}
void convert(char h[12]) {
  int i, l;
  strcpy(bit, "");
  l = strlen(h);
  for (i = 0; i < l; i++) {
    switch (h[i]) {
    case '0':
      strcat(bit, "0");
      break;
    case '1':
      strcat(bit, "1");
      break;
    case '2':
      strcat(bit, "10");
      break;
    case '3':
      strcat(bit, "11");
      break;
    case '4':
      strcat(bit, "100");
      break;
    case '5':
      strcat(bit, "101");
      break;
    case '6':
      strcat(bit, "110");
      break;
    case '7':
      strcat(bit, "111");
      break;
    case '8':
      strcat(bit, "1000");
      break;
    case '9':
      strcat(bit, "1001");
      break;
    case 'A':
      strcat(bit, "1010");
      break;
    case 'B':
      strcat(bit, "1011");
      break;
    case 'C':
      strcat(bit, "1100");
      break;
    case 'D':
      strcat(bit, "1101");
      break;
    case 'E':
      strcat(bit, "1110");
      break;
    case 'F':
      strcat(bit, "1111");
      break;
    }
  }
}
