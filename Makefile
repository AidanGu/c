CC = clang

all: send_emails

send_emails: send_emails_main.o network.o emails.o
	$(CC) send_emails_main.o network.o emails.o -o send_emails

network.o: network.c network.h
	$(CC) -c network.c

emails.o: emails.c network.h
	$(CC) -c emails.c

send_emails_main.o: send_emails_main.c emails.h
	$(CC) -c send_emails_main.c

clean:
	rm -rf send_emails emails.o send_emails_main.o network.o
