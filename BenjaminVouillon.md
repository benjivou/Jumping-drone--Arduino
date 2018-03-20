# Jour 1 (12/01/18):
-  Création du Github  
-  Découverte des piéces du moteur  
-  Recherche de la solution d'éclairage du drone   
-  Création d'une maquette low cost pour les moteurs ![maquette](https://raw.githubusercontent.com/benjivou/Jumping-drone--Arduino/master/Image/Ben/Maquette1.jpg)

# Jour 2 (18/01/18):  
-  Test carte moteur (https://wiki.mchobby.be/index.php?title=Pont-H_L298N#Ressources) = OK  
-  Test moteur 9V rectangle    
=> **Probléme de couple : les roues ne sont pas entrainées!!**

# Jour 3 (23/01/2018):
-  Présentation du projet devant la classe 
-  Résolution du probléme des moteurs : La pile était HS
-  Installation des roues
=> Controle des moteurs avec la carte

# Jour 3.5 (27/01/2018):
-  Maîtrise du controle des moteurs sans bluetooth  
-  Pour faciliter les manipulations j'ai démonter la maquettes pour avoir un espace de travail plus facile ![test moteur](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Image/Ben/testmoteur.png)  
=> Controle avec le Bluetooth  
=> **Comment gérer le controle du moteur + les éclairages sans conflit et en même temps?**  

# Jour 3.7 (30/01/2018):  
-  Remontage de la maquette avec des matériaux démontables  
-  Utilisation du Velcro pour démonter et permettre de changer l'équilibre du Drone  
-  Création d'une alimentation 8.2V avec un chargeur pour tester à la maison la construction  

# Jour 4 (07/02/2018):
-  Test du drone sous 9v,et... ca marche bien  
-  J'ai commencé à réfléchir à un nouveau mode de programmation car on va avoir un soucis, si l'utilisateur commande les LEDs pendant ce temps le drone ne peut se déplacer.  
=> **Comment réussir à géré le controle de toutes les tâches du drones?  Comment gérer les arguments de controle (couleur LED, vitesse,...)?**  
==> **Idée: J'ai trouvé un mode programmation utilis dans ce cas, LES INTERRUPTIONS, le fait de créer des tâches prioritaires pour interrompre le cours normal de la Loop. (  https://www.allaboutcircuits.com/technical-articles/using-interrupts-on-arduino/     http://www.locoduino.org/spip.php?article64).**  
=> Objectif scéance suivante:  
-  Il faut trouver une architecture logiciel qui permet gérer le controle multitache.  
-  Apprendre la prog des interruptions. 

# Jour 4.5 (27/02/2018):
-   j'ai trouvé un site avec les modèles 3d du sumo  parrot,  problème de piéce solutionné
http://m.yeggi.com/q/parrot+jumping+sumo/?s=tx  
-  J'ai refait l'architecture du code et fait la partie centrale du probléme : Coeur.  

# Jour 5 (16/03/2018):
-  Les moteurs sont demandés  
-  J'ai fait la méthode Spliter, elle récupére le mot de Coeur pour le distribuer au bloc demandé dans la requête  
==> **Objectif prochaine scéance: Faire fonctionner Spliter, et Coeur ensemble. Réecrire le moteur. Réaliser la présentation de nos avancements.  

# Jour 5.5 (20/03/2018):
-  Les moteurs sont arrivés, ils ont plus de couple que les anciens moteurs, ils sont 4 fois plus petits, plus léger et fonction sous 3V à 6 V, Il nemanque plus qu'à les testé sur une nouvelle maquette.  
-  J'ai fini le code générale, désormais, l'arduino sait receptionner un message dans le buffer, le convertir en message pour les blocs ( moteur, led, saut) et distribue un message bien qualibré pour chaque bloc.  https://github.com/benjivou/Jumping-drone--Arduino/code/BenjaminVouillon/COde/Realease/Realease_180320.ino 
