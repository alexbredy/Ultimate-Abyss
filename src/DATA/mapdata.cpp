#include <stdio.h>
#include <String>
#include <iostream>

#include "SDL/SDL.h"
#include "../gameengine.h"
/*OBLIGATOIRE!! la déclaration de la classe dans character.h ne nous permet pas de travailler
sur ladite classe d'où l'obligation d'include le fichier ici (et la déclaration cyclique n'existe plus étant donné que nous
sommes dans le .cpp*/
#include "mapdata.h"
#include "tinyxml.h"
#include "imagesetup.h"
using namespace std;

void MapData::Init()
{
    int tempId;
    string tempName;
    string tempMainImage;
    string tempPhysicalDataImage;
    int tempWidth;
    int tempHeight;

    TiXmlDocument doc( "DATA/mapDataInitROM.xml" );
    if(doc.LoadFile()){
        printf("FILE LOADED\n");}
    else{
        printf("THE FILE DOES NOT EXIST");}

    TiXmlHandle hdl(&doc);

    TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();
	if(!elem)
        {cerr << "THIS NODE DOESN'T EXIST" << endl;}
	else{

	    //Setup first map

	    elem->QueryIntAttribute("id",&tempId);
	    tempName = elem->Attribute("name");
	    tempMainImage = elem->Attribute("mainImage");
	    tempPhysicalDataImage=elem->Attribute("physicalDataImage");
	    elem->QueryIntAttribute("width",&tempWidth);
	    elem->QueryIntAttribute("height",&tempHeight);


	    ancientWay.setId(tempId);
	    ancientWay.setName(tempName);
	    ancientWay.setSize(tempWidth, tempHeight);
	    ancientWay.setMainImage(tempMainImage);
	    ancientWay.setPhysicalDataImage(tempPhysicalDataImage);
	}




}

Map& MapData::getAncientWay()
{
    return ancientWay;
}

//EVENTS

