#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator it_begin = this->arr_spell.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->arr_spell.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->arr_spell.clear();
}

void SpellBook::learnSpell(ASpell* spell_ptr)
{
    if (spell_ptr)
        arr_spell.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell *>::iterator it = arr_spell.find(spell_name);
	if (it != arr_spell.end())
		delete it->second;
    arr_spell.erase(spell_name);
}

ASpell* SpellBook::createSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell *>::iterator it = arr_spell.find(spell_name);
    if (it != arr_spell.end())
        return arr_spell[spell_name];
    return NULL;
}
