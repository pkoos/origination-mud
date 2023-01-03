#include "MudServer.hpp"
#include "MudEntity.hpp"
#include <iostream>


/*    
    1. Create a socket.
    2. Bind socket to an address.
    3. Listen for connections.
    4. Accept a connection.
*/


int main(int argc, char ** argv) {
    MudEntity newCharacter = MudEntity();
    newCharacter.setName("Excrutio");
    std::cout << "Character name: '" << newCharacter.getName() << "'" << std::endl;

    newCharacter.setDescription("A wild and crazy guy from the north.");

    std::cout << "Character Description: " << newCharacter.getDescription() << std::endl;
    
    newCharacter.addKeyword("Excrutio");
    newCharacter.addKeyword("Player");
    newCharacter.addKeyword("mob");

    std::vector<string> testKeywords = {"Excrutio", "mob", "NPC" };

    for(string keyword : testKeywords) {
        std::cout << "Is " << keyword << " a character keyword? " << newCharacter.isKeyword(keyword) << std::endl;
    }

    return 0;
}

// int main(int argc, char ** argv) {
//     MudServer server = MudServer(3490);
//     std::cout << "Server port: " << server.getPort() << std::endl;
//     std::cout << "Server File Descriptor: " << server.getServerFD() << std::endl;
//     server.reuseAddress();
//     return 0;
// }
