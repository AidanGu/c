#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

char *bitwise_xor_text(char *message, char *pad, size_t text_length) {
  char *output = calloc(text_length + 1, sizeof(char));

  for(size_t i = 0; i < text_length; i++) {
    output[i] = message[i] ^ pad[i];
  }
  return output;
}

char *generate_pad(size_t text_length) {
  char *output = calloc(text_length + 1, sizeof(char));

  for(size_t i=0; i < text_length; i++) {
    char byte = (char)rand() % 256;
    output[i] = byte;
  }
  return output;
}

int main(void) {
  // initialize RNG
  srand(time(NULL));

  char* secret_message = ("This weekend, some of us went cherrypicking and"
    " very few people got injured.");
  size_t len = strlen(secret_message);

  char* pad = generate_pad(len);
  char* encrypted = bitwise_xor_text(secret_message, pad, len);

  printf("ciphertext: %s\n", encrypted);

  char *decrypted = bitwise_xor_text(encrypted, pad, len);
  printf("decrypted again: %s\n", decrypted);

  return 0;
}
