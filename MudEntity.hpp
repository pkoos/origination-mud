#ifndef MUD_ENTITY_H
#define MUD_ENTITY_H

#include <string>
#include <vector>

using namespace std;

class MudEntity {
    private:
        string _name;
        string _description;
        vector<string> _keywords;
    
    public:
        MudEntity() { };
        string getName();
        void setName(string name);
        string getDescription();
        void setDescription(string description);
        void addKeyword(string word);
        bool isKeyword(string word);
};

#endif
