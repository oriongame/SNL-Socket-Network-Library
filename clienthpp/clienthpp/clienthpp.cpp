#include "..\..\Socket.hpp"

using namespace std::chrono_literals;
std::chrono::time_point<std::chrono::steady_clock> start;
std::chrono::time_point<std::chrono::steady_clock> end;

void ReadPacket(std::socket_t Socket, std::base_socket::byte_t *Buffer)
{
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	printf("\nPacket[%d - %lf ms]: %s", Socket, elapsed.count(), Buffer);
}

int main()
{
	std::base_socket::init_socket();
	std::client client;

	for (int32_t i = 0; i < 10000; i++)
	{
	
	  client.Connect("127.0.0.1", 500, std::arch_server_t::tcp_thread);
	  client.Run(std::type_blocked_t::non_block);

	}

	for (;;)
	{
		Sleep(500);
	}
    return 0;
}

