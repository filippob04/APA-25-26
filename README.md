# 📊 APA - Analisi e Progettazione di Algoritmi

Repository dedicata al corso di **Analisi e Progettazione di Algoritmi** (Laurea Triennale in Informatica, Università degli Studi di Genova).

Questo spazio raccoglie una serie di progetti, script e relazioni tecnico-teoriche sviluppati per analizzare, implementare e testare algoritmi avanzati, sia deterministici che randomizzati. Ogni modulo unisce un rigoroso formalismo matematico all'efficienza computazionale del codice, documentando approfonditamente l'andamento asintotico e le proprietà algebriche delle strutture dati utilizzate.

Nonostante la natura eterogenea dei temi trattati — che spaziano dalla programmazione dinamica ai sistemi distribuiti e alla crittografia —, **tutti i laboratori presenti sono completi, verificati e corredati della rispettiva documentazione formale (PDF)**.

## 🗂️ Struttura della Repository e Moduli Analizzati

Ogni argomento è isolato nella propria cartella dedicata, strutturata come un ambiente a sé stante contenente il codice sorgente (Jupyter Notebook `.ipynb`) e il rispettivo report (`.pdf`).

I principali moduli inclusi sono:

- **`PrimalityTest/` (Test di Primalità di Miller-Rabin)**
  - _Teoria & Analisi:_ Studio del Piccolo Teorema di Fermat, delle radici quadrate dell'unità e della struttura del sottogruppo proprio $H_{n} < \mathbb{Z}^*_{n}$. Dimostrazione teorico-pratica applicata al modulo composto $n = 65$, verifica del Teorema di Lagrange e individuazione di _MR-Testimoni_ banali e non banali.
  - _Complessità:_ $\mathcal{O}(k(\log n)^3)$.
- **`LCS/` (Longest Common Subsequence)**
  - _Teoria & Analisi:_ Analisi comparativa tra l'approccio esaustivo (Brute Force da $2^m \cdot n$) e l'ottimizzazione tramite Programmazione Dinamica. Implementazione a spazio ridotto $\Theta(m+n)$ mediante il trucco del mantenimento selettivo delle righe contigue della matrice di allineamento.
- **`Prim/` (Minimum Spanning Tree)**
  - _Teoria & Analisi:_ Implementazione Greedy dell'algoritmo di Prim per la ricerca dell'albero di ricoprimento minimo in grafi non orientati estratti da file ASCII. Gestione efficiente della frangia di nodi adiacenti tramite code a priorità strutturate ad Heap.
  - _Complessità:_ $\mathcal{O}((n+m)\log n)$ ottimizzata con `heapdict`.
- **`Quicksort/` (Randomized Quicksort - Las Vegas & Monte Carlo)**
  - _Teoria & Analisi:_ Studio dell'impatto della randomizzazione nell'algoritmo di ordinamento per abbattere il caso peggiore quadratico $O(n^2)$. Analisi empirica e probabilistica del numero atteso di confronti (bound a $O(n \log n)$) validata tramite simulazioni statistiche e disuguaglianze di Markov / Chebyshev.
- **`ByzantineAgreement/` (Accordo Bizantino & Consensus)**
  - _Teoria & Analisi:_ Analisi di un problema decisionale e di consenso distribuito tra $n$ processi in presenza di nodi _faulty_ o malevoli. Simulazione round-by-round (Round 0 e Round 1) con lancio di moneta globale, verificando i vincoli di _Agreement_, _Validity_ e _Termination_ sotto la condizione stretta $n \ge 3f + 1$.

## 🚀 Come esplorare ed eseguire il codice

Poiché gli algoritmi affrontano paradigmi computazionali differenti, i laboratori sfruttano la flessibilità dell'ambiente **Python 3** unito all'interattività dei Jupyter Notebooks per il plotting dei dati e la validazione empirica.

Per riprodurre le simulazioni:

1. Navigare all'interno della cartella del modulo d'interesse.
2. Consultare il file `.pdf` per comprendere i vincoli formali, i trace manuali e le metriche di test.
3. Eseguire le celle del notebook `.ipynb` per avviare l'implementazione software e visualizzare l'output degli algoritmi.

## 👤 Autore

**filippob04**

- Studente di Informatica - Università degli Studi di Genova (UniGe)
- Corso: Analisi e Progettazione di Algoritmi (APA) A.A. 25-26
- GitHub: [@filippob04](https://github.com/filippob04)

Nel corso dello sviluppo, sono stati utilizzati strumenti di intelligenza artificiale generativa esclusivamente come supporto di debug sintattico e chiarimento di specifici concetti teorici con un minimo intervento per l'ottimizzazione del codice, senza l'utilizzo di script o testi pre-generati da terzi.
