#include <stdio.h>
#include <iostream>
#
#include <sstream>
#include "gameengine.h"
#include "stats.h"

void Stats::setLevel(int value)
{
    this->level=value;}

void Stats::setHp(int value)
{
    this->hp=value;}

void Stats::setHpMax(int value)
{
    this->hpMax=value;}

void Stats::setMp(int value)
{
    this->mp=value;}

void Stats::setMpMax(int value)
{
    this->mpMax=value;}

void Stats::setCp(int value)
{
    this->cp=value;}

void Stats::setCpMax(int value)
{
    this->cpMax=value;}

void Stats::setStrength(int value)
{
    this->strength=value;}

void Stats::setMagic(int value)
{
    this->cpMax=value;}

void Stats::setDefense(int value)
{
    this->defense=value;}

void Stats::setMagicDefense(int value)
{
    this->magicDefense=value;}

void Stats::setAgility(int value)
{
    this->agility=value;}

void Stats::setEvasion(int value)
{
    this->evasion=value;}




int Stats::getLevel(){
    return level;}

int Stats::getHp(){
    return hp;}

int Stats::getHpMax(){
    return hpMax;}

int Stats::getMp(){
    return mp;}

int Stats::getMpMax(){
    return mpMax;}

int Stats::getCp(){
    return cp;}

int Stats::getCpMax(){
    return cpMax;}

int Stats::getStrength(){
    return strength;}

int Stats::getMagic(){
    return magic;}

int Stats::getAgility(){
    return agility;}

int Stats::getEvasion(){
    return evasion;}

int Stats::getDefense(){
    return defense;}

int Stats::getMagicDefense(){
    return magicDefense;}
