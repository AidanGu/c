#include "emails.h"
#include "network.h"

#include <stdio.h>

void send_email()
{
  printf("hello I have sent the email to port: %d\n", email_port());
}
