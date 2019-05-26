# Il linguaggio ILD
ILD nasce dalla necessità di semplificare lo sviluppo di programmi basati sul linguaggio assemblativo EsEDM.

*Proponiamo un linguaggio __semplice__ e __intuitivo__ che, nei limiti implementativi legati alla nostra inesperienza, riesce a eseguire alcune operazioni matematiche, logiche e binarie.*

---
## Tabella dei Contenuti
  - [Le basi del linguaggio ILD](#le-basi-del-linguaggio-ild)
  - [Tipi primitivi](#tipi-primitivi)
  - [Array](#array)
  - [Operazioni aritmetiche](#operazioni-aritmetiche)
  - [Operazioni logiche](#operazioni-logiche)
  - [Strutture Condizionali](#strutture-condizionali)
  - [Strutture di Ciclo](#strutture-di-ciclo)
  - [Codice Esempio](#codice-esempio)

---
## Le basi del linguaggio ILD
- Un file di codice sorgente ILD ha come estensione __.ild__ ;
- Il linguaggio ILD è *__case-insensitive__* per quanto riguardi le parole chiave;
- La stesura di codice ILD è caratterizzata da una sezione a blocchi:
    1. Il blocco *__#dichiarazione__* dov'è possibile dichiarare tutte le variabili che si intendono utilizzare e inizializzarle con valori immediati.
    2. Il blocco *__#esecuzione__* dov'è possibile eseguire calcoli e operazioni.
- I due blocchi devono essere *__aperti__* e *__chiudi__* tramite header di apertura e chiusura:
    1. _#dichiarazione_ -> _#fine-dichiarazione_
    2. _#esercuzione_ -> _#fine-esecuzione
- Ogni riga contiene un'istruzione che __deve terminare__ con un punto e virgola (__;__);
- Vi è un massimo di 300 variabili utilizzabili;
- I nomi delle variabili possono contenere solo caratteri alfa-numerici;
- L'assegnazione di un dato a una variabile viene indicata attraverso l'operatore di assegnamento (**=**);
---
## Tipi primitivi
I tipi primitivi sono essenzialmente la tipologia di dati che è possibile manipolare all'interno del linguaggio ILD:
1. **INTERO** *[nome]*
   * Un dato numerico intero che può assumere un valore del range: [range_minore , range_massimo] (estremi inclusi)
2. **CARATTERE** *[nome]*
   * Un dato che può contienere una lettera stampabile a schermo (la tabella di riferimento è ASCII)
3. **BOOLEANO** *[nome]*
   * Un dato numerico intero usato per indicare condizione di verità che può assumere come valori:
      * **1** : per indicare condizione di verità
      * **0** : per indicare condizione di falsità
---
## Array
In ILD è possibile creare array __mono-dimensionali__ dei dati primitivi elencati precedentemente. Per la loro dichiarazione è necessario sapere a priori la dimensione dell'array.

Alla dichiarazione dell'array è possibile inizializzarlo con una serie di valori separati da una virgola all'interno di un blocco __sulla stessa riga della dichiarazione__ delimitato dalle parentesi graffe.
1. **INTERO[DIMENSIONE]** *[nome]*
   * Un array di interi non inizializzato
2. **CARATTERE[DIMENSIONE]** *[nome]* = {A,B,C,...,Z}
   * Un array di caratteri inizializzato con l'alfabeto
3. **BOOLEANO[DIMENSIONE]** *[nome]*
   * Un array di booleani

L'assegnazione o la lettura di un dato nell'array avviene tramite l'operatore di indici (__[indice]__).
Il conteggio degli indici inizia da __0__ fino a un valore pari a __DIMENSIONE-1__

---
## Operazioni aritmetiche
* <[destinazione]> = <[operando_1]> + <[operando_2]>
* <[destinazione]> = <[operando_1]> - <[operando_2]>
* <[destinazione]> = <[operando_1]> * <[operando_2]>
* <[destinazione]> = <[operando_1]> / <[operando_2]>
* <[destinazione]> = <[operando_1]> % <[operando_2]>
* <[destinazione]> = <[operando_1]> ^ <[operando_2]>
* <[destinazione]> = <[operando_1]> == <[operando_2]>
* <[destinazione]> = <[operando_1]> != <[operando_2]>
* <[destinazione]> = <[operando_1]> > <[operando_2]>
* <[destinazione]> = <[operando_1]> < <[operando_2]>
* <[destinazione]> = <[operando_1]> >= <[operando_2]>
* <[destinazione]> = <[operando_1]> <= <[operando_2]>

## Operazioni logiche
* <[destinazione]> = <[operando_1]> & <[operando_2]>
* <[destinazione]> = <[operando_1]> | <[operando_2]>

## Strutture Condizionali
Il linguaggio ILD implementa solo una struttura condizionale:
* **if**(_condizione_) <da implementare>

## Strutture di Ciclo
Il linguaggio ILD implementa solo una struttura di ciclo:
* **while**(_condizione_) <da implementare>
## Codice Esempio
Segue un piccolo codice ILD d'esempio:
```
Da definire
```
