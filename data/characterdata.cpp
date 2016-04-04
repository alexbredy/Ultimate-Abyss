#include <stdio.h>
#include <String>
#include <iostream>
#include <sstream>

#include "../gameengine.h"
/*OBLIGATOIRE!! la déclaration de la classe dans character.h ne nous permet pas de travailler
sur ladite classe d'où l'obligation d'include le fichier ici (et la déclaration cyclique n'existe plus étant donné que nous
sommes dans le .cpp*/
#include "characterdata.h"
#include "tinyxml.h"
using namespace std;

void CharacterData::Init()
{
    int tempId;
    string tempName;
    int tempLevel;
    int tempHp;
    int tempHpMax;
    int tempMp;
    int tempMpMax;
    int tempCp;
    int tempCpMax;
    int tempStrength;
    int tempMagic;
    int tempDefense;
    int tempMagicDefense;
    int tempAgility;
    int tempEvasion;

    //Set character general data

    TiXmlDocument doc( "DATA/characterDataInitROM.xml" );

    if(doc.LoadFile()){
        printf("FILE LOADED\n");}
    else{
        printf("THE FILE DOES NOT EXIST");}

    TiXmlHandle hdl(&doc);


	TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();
	if(!elem)
        {cerr << "THIS NODE DOESN'T EXIST" << endl;}
	else{

	    //setting Kholkir init attributes

	    kholkir.Init();

	    elem->QueryIntAttribute("id",&tempId);
	    tempName = elem->Attribute("name");
	    elem->QueryIntAttribute("level",&tempLevel);
	    elem->QueryIntAttribute("hp",&tempHp);
	    elem->QueryIntAttribute("hpMax",&tempHpMax);
	    elem->QueryIntAttribute("mp",&tempMp);
	    elem->QueryIntAttribute("mpMax",&tempMpMax);
	    elem->QueryIntAttribute("cp",&tempCp);
	    elem->QueryIntAttribute("cpMax",&tempCpMax);
	    elem->QueryIntAttribute("strength",&tempStrength);
	    elem->QueryIntAttribute("magic",&tempMagic);
	    elem->QueryIntAttribute("defense",&tempDefense);
	    elem->QueryIntAttribute("magicDefense",&tempMagicDefense);
	    elem->QueryIntAttribute("agility",&tempAgility);
	    elem->QueryIntAttribute("evasion",&tempEvasion);

	    kholkir.setId(tempId);
	    kholkir.setName(tempName);
	    kholkir.getStats().setLevel(tempLevel);
	    kholkir.getStats().setHp(tempHp);
	    kholkir.getStats().setHpMax(tempHpMax);
	    kholkir.getStats().setMp(tempMp);
	    kholkir.getStats().setMpMax(tempMpMax);
	    kholkir.getStats().setCp(tempCp);
	    kholkir.getStats().setCpMax(tempCpMax);
	    kholkir.getStats().setStrength(tempStrength);
        kholkir.getStats().setMagic(tempMagic);
        kholkir.getStats().setDefense(tempDefense);
        kholkir.getStats().setMagicDefense(tempMagicDefense);
        kholkir.getStats().setAgility(tempAgility);
        kholkir.getStats().setEvasion(tempEvasion);

        elem = elem->NextSiblingElement();
	}
    if(!elem)
        {cerr << "THIS NODE DOESN'T EXIST" << endl;}
	else{

	    //setting Zika init attributes

	    zika.Init();

	    elem->QueryIntAttribute("id",&tempId);
	    tempName = elem->Attribute("name");
	    elem->QueryIntAttribute("level",&tempLevel);
	    elem->QueryIntAttribute("hp",&tempHp);
	    elem->QueryIntAttribute("hpMax",&tempHpMax);
	    elem->QueryIntAttribute("mp",&tempMp);
	    elem->QueryIntAttribute("mpMax",&tempMpMax);
	    elem->QueryIntAttribute("cp",&tempCp);
	    elem->QueryIntAttribute("cpMax",&tempCpMax);
	    elem->QueryIntAttribute("strength",&tempStrength);
	    elem->QueryIntAttribute("magic",&tempMagic);
	    elem->QueryIntAttribute("defense",&tempDefense);
	    elem->QueryIntAttribute("magicDefense",&tempMagicDefense);
	    elem->QueryIntAttribute("agility",&tempAgility);
	    elem->QueryIntAttribute("evasion",&tempEvasion);

	    zika.setId(tempId);
	    zika.setName(tempName);
	    zika.getStats().setLevel(tempLevel);
	    zika.getStats().setHp(tempHp);
	    zika.getStats().setHpMax(tempHpMax);
	    zika.getStats().setMp(tempMp);
	    zika.getStats().setMpMax(tempMpMax);
	    zika.getStats().setCp(tempCp);
	    zika.getStats().setCpMax(tempCpMax);
	    zika.getStats().setStrength(tempStrength);
        zika.getStats().setMagic(tempMagic);
        zika.getStats().setDefense(tempDefense);
        zika.getStats().setMagicDefense(tempMagicDefense);
        zika.getStats().setAgility(tempAgility);
        zika.getStats().setEvasion(tempEvasion);
	}

	//Set character graphics data

	kholkir.setWalkFieldImage("IMG/kholkirWalk.png");
	kholkir.setFaceImage("IMG/face1.png");


	//INITIALISATION des paramètres

	kholkir.getFieldSprite().setEnabled(true);

	kholkir.getFieldSprite().setCoordinates(400,300);
	kholkir.getFieldSprite().getPhysicalSprite().x=0;
	kholkir.getFieldSprite().getPhysicalSprite().y=0;
	kholkir.getFieldSprite().getPhysicalSprite().w=32;
	kholkir.getFieldSprite().getPhysicalSprite().h=10;
	kholkir.getFieldSprite().updatePhysicalSprite();

	kholkir.setCurrentFieldImage(kholkir.getWalkFieldImage());

	kholkir.getFieldSprite().setImage(kholkir.getCurrentFieldImage());
	kholkir.getFieldSprite().setDirection("southEast");
	kholkir.getFieldSprite().setFrame(0);
	kholkir.getFieldSprite().setCurrentFramePeriod(0);
	kholkir.getFieldSprite().setTotalFramePeriod(12);
	kholkir.getFieldSprite().setClip8x8(128,128);

}

Character& CharacterData::getKholkir()
{
    return kholkir;
}

Character& CharacterData::getZika()
{
    return zika;
}
