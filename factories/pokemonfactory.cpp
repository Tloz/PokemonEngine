#include "../inc/pokemonfactory.h"

#include <iomanip>
#include <iostream>


// string PokeFactory::ressourcesFolder()
// {
//     return m_ressourcesFolder;
// }

// string PokeFactory::speciesFolder()
// {
//     return m_speciesFolder;
// }


Specie PokeFactory::createSpecie(int id, int variantID)
{
    // On accède au dossier des espèces
    //string fileName = PokeFactory::ressourcesFolder();// + PokeFactory::speciesFolder();
    string fileName = "assets/";
    fileName += "species/";

    // On ajoute des 0 de padding pour avoir le bon nom de fichier
    std::stringstream ss;
    ss << std::setw(3) << std::setfill('0') << id;
    fileName += ss.str();

    // On ajoute au besoin la forme
    if(variantID != 0)
        fileName += "-" + to_string(variantID);

    // On ajouts l'extension
    fileName += ".specie";

    return Specie(fileName);
}