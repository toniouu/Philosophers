philosophers

philosophers est un projet de l'école 42 Antananarivo qui consiste à simuler un problème classique en informatique : le problème des philosophes. Ce projet m'a permis d'approfondir mes connaissances sur les threads, la synchronisation et la gestion de ressources partagées.


📜 Description

Le projet simule plusieurs philosophes qui mangent, réfléchissent et dorment autour d'une table. Chaque philosophe doit alterner entre ces trois états, mais l'accès aux fourchettes (ressources partagées) doit être bien synchronisé pour éviter les conditions de course et les blocages. Ce projet m'a permis de travailler sur la gestion des threads et de comprendre les principes fondamentaux de la programmation concurrente.


🔧 Fonctionnalités

🍴 Gestion des philosophes : Chaque philosophe doit avoir accès à deux fourchettes pour manger.

🔄 Synchronisation des threads : Utilisation des mutex pour éviter les conditions de course (data races).

🕰 Gestion du temps : Chaque philosophe a un temps de vie limité, ce qui implique une gestion du timing des actions (manger, penser, dormir).

🚀 Optimisation des performances : Réduire les risques de blocage (deadlock) et de famine (starvation) des philosophes.


🎯 Pourquoi ce projet ?

Ce projet m'a permis de comprendre les mécanismes de synchronisation des threads et de gestion des ressources partagées en C. En travaillant sur ce projet, j'ai appris à résoudre des problèmes complexes liés à la concurrence, à optimiser le code pour éviter les blocages et à utiliser des outils de synchronisation pour garantir le bon fonctionnement du programme.



Clone ce dépôt pour tester ou utiliser cette implémentation :

    git clone https://github.com/toniouu/philosophers.git
