cmp: server client

svr: server.c pipe_networking.h
	gcc server.c pipe_networking.h -o server

client: client.c pipe_networking.h
	gcc client.c pipe_networking.h -o client

clean:
	rm -f server client
	rm *~