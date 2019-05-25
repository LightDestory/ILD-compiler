# <ILD_compiler>
[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

## Descrizione del progetto
Progetto dedicato al corso di Archittetura degli Elaboratori dell'Università degli Studi di Catania A.A 2018/2019.
Con tale progetto si sperimenta lo sviluppo di un *__semplice__* linguaggio ad alto livello denominato _ILD_ e di un suo compilatore, _ild-compiler_ scritto in C++, a un linguaggio assemblativo non standard denominato _EsEDM_.

## Specifiche del linguaggio ad alto livello ILD
Le specifiche del linguaggio ILD sono consultabili nella documentazione allegata al progetto e indicata di seguito:

[Specifiche del linguaggio ILD](https://github.com/LemuelPuglisi/ILD-compiler/blob/master/documentazione/language.md)

## Specifiche del compilatore
Le specifiche del compilatore sono consultabili nella documentazione allegata al progetto e indicata di seguito:

[Specifiche del compilatore](https://github.com/LemuelPuglisi/ILD-compiler/blob/master/documentazione/compiler.md)

## Piccolo confronto ILD <-> EsEDM
Da compilare

[da compilare](NULL)

## Requisiti per una build fai-da-te del compilatore
Per compilare da codice sorgente è necessario avere:
* Un qualsiasi S.O (_Windows, Linux, MacOS_) dotato di g++

Soddisfatti i requisiti, è possibile compilare da sorgente:
1. Scarica una copia della repository sul tuo computer:
   1. Puoi usare il comando __git clone__ ([clicca qui per la documentazione](https://git-scm.com/docs/git-clone))
   2. Cliccare sul tasto __"Clone or Download"__ presente nella pagina del repository e scaricare l'archivio ZIP. Estrai in una locazione a piacere il contenuto.
2. Esegui il corretto script di compilazione a seconda del S.O:
   1. _Windows_: make_win.bat
   2. _Linux/MacOS_: make_linux.sh 
      + Potrebbe essere necessario dare i permessi di esecuzione al file prima di poterlo eseguire.
3. Al termine della compilazione il file sarà situato all'interno della cartella __ild_compiler/output/__

__Nota*:__ _Potrebbe essere necessario eseguire lo script con i diritti di amministratore qualora la repository si trovi in locazioni particolari._

## Compilare un sorgente ILD
Per compilare un sorgente ILD è necessario possedere l'eseguibile del ild_compiler ed eseguire il seguente comando:
1. __ild_compiler.exe -c__ <file_sorgente> <file_output>

__Nota*:__ _Per maggiori informazioni sull'uso del compilatore si faccia riferimento alla documentazione sulle specifiche del compilatore._

## Built With
* [C++] [Regex] [StackOverflow]

## Autori del progetto
* [**Lemuel Puglisi**](https://lemuelpuglisi.github.io/)
* [**Alessio Tudisco**](https://lightdestoryweb.altervista.org)
