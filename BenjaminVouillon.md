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
