# Il compilatore ILD -> EsEDM
IL compilatore nasce dalla necessità di passare dal linguaggio ad alto livello ILD al linguaggio assemblativo non standard EsEDM.

*Proponiamo un compilatore __semplice__ che, nei limiti implementativi legati alla nostra inesperienza, riesce a compilare codice ILD testato da noi*

---
## Table of Contents
1. [I comandi](#i-comandi)
2. Da definire

---
## I comandi
Il compilatore presenta i seguenti comandi:
* __ild_compiler.exe -h__ : visualizza l'elenco dei comandi
* __ild_compiler.exe -i__ : visualizza le informazioni sul progetto
* __ild_compiler.exe -v__ : visualizza la versione del compilatore in uso
* __ild_compiler.exe -c__ <file_sorgente> <file_output> : esegue la compilazione del <file_sorgente> e salva l'eseguibile come <file_output>
* __ild_compiler.exe -dc__ <file_sorgente> <file_output> : esegue la compilazione del <file_sorgente> e salva l'eseguibile come <file_output> in modalità di debug, ovvero con la stampa degli eventi in console
