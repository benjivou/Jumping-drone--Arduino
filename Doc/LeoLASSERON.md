# Jour 1:   
-  Test des leds RGB et du registre (http://www.zem.fr/decouverte-du-composant-74hc595-8-bit-shift-register/)  
# Jour 2:   
-  Le registre à led ne semble pas la meilleure solution, l'utilisation d'un ruban de LED sera plus adapté à ce que l'on souhaite faire que cela soit techniquement ou esthétiquement. Je commande donc un ruban de leds RGB et installe la librairie adafruit NeoPixel
# Jour 3:   
-  Comme je n'ai pas reçu mon rubans de leds, je code la partie du programme qui fera faire un allez-retour de 0 à 180 degrés au servo-moteur. Je commence à me renseigner pour la partie autour du saut et je trouve un modele 3D d'une pièce du système de saut du robot parrot qui est notre inspiration. Je le télécharge en vue de l'imprimer plus tard.
# Jour 4:   
-  J'ai reçu mon ruban de leds, je commence donc à coder différentes fonctions lumineuses en m'aidant des exemples de la librairie.
# Jour 5:   
-  Je code le programme qui prend en argument le mode lumineux à lancer sur les leds et l'execute, à termes cet argument sera transmis via bluetooth. J'ai codés plusieurs modes lumineux, arc-en-ciel, fixe, clignotant. 
# Jour 6:   
-  En recherchant comment coder un mode lumineux ( respiration ) je tombe sur le github d'une librairie (WS2812FX) simlifiant la librairie adafruit NeoPixel et qui possède déjà des fonctions prédifinis simples à utiliser et déclanchant divers mode lumineux. J'installe donc cette librairie afin de simplifier mon code et de pouvoir ajouter plusieurs modes lumineux facilement ( Larson, arc-en-ciel,fixe,clignotant,respiration). 
# Jour 7:   
- Le programme autour des leds et des différents mode lumineux séléctionnables est terminé j'essaye de le fusionner dans le code de Benjamin qui reçoit et traite les requetes bluetooth mais je rencontre des problèmes de variables. Je laisse cette tache de coté en attendant que Benjamin finisse complétement sa partie autour des moteurs et puisse m'aider.
# Jour 8:   
- Je commence la partie mécanique autour du saut, je vais au fab lab pour faire imprimer la pièce qui nous servira à comprimer le ressort puis a le relacher avec le servo moteur.Je récupère la pièce qui s'est correctement imprimé.

![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/33994757_1796599723719975_7744947553728200704_n.jpg?raw=true)
# Jour 9:   
- Fabriquation de la queue du drone à l'aide tige filetées métaliques et ajout des ressorts sur chacun des axes.
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34092525_1796599417053339_4037321867294408704_n.jpg?raw=true)
# Jour 10:   
- Nous allons au fab lab avec Benjamin pour découper le chassis que nous avons schématisé sur feuille dans une planche de plexi. On y perce tous les trous pour les fixations et on découpe également la pièce de bois dans laquelle les axes de la queue coulisseronts.
# Jour 11:   
- Benjamin fusionne les deux codes, ainsi je peut tester ma méthode pour les leds et le servo moteur. Cela fonctionne mais nous avons un problème d'alimentation externe, on doit changer de carte arduino. 
# Jour 12:   
- Je doit m'occuper du montage du drone, je fait un premier test de montage en utilisant une breadboard. L'alimentation externe fonctionne bien mais elle n'est pas assez puissante. L'arduino crash dès qu'elle reçoit une instruction quand les deux moteurs des roues et les leds sont branchés. Je récupère une seconde alimentation afin de palier à ce problème. Je test le drone monté ainsi de manière provisoire, toutes les instructions de pilotage et de leds fonctionnent. Toutefois le drone dévie de trajectoire en marche arrière.
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34047741_1796599660386648_6835009258342318080_n.jpg?raw=true)
# Jour 13:   
- Je réalise la première partie du montage finale : souder sur une plaquette tous nos composants ainsi que tous nos fils afin de retirer la breadboard. Il y'a beaucoups de soudures cela prend donc beaucoup de temps mais dès les premiers test cela fonctionne, mes soudures fonctionnent et la plaquette aussi.
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34014152_1796599617053319_1300151566174519296_n.jpg?raw=true)
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34011450_1796599613719986_6481184303400091648_n.jpg?raw=true)
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34064633_1796599570386657_5680080389100535808_n.jpg?raw=true)
# Jour 14:   
- Je relie le servo moteur que je n'avais pas pu tester avec l'alimentation externe à la plaquette et l'arduino crash de nouveau. J'ajoute donc une troisème pile au montage. Je finalise la plaquettes avec les derniers fils à souder et je commence le montage final.
L'agancement est très serré, je scotch donc chaque cable afin qu'il ne gène pas fonctionnement du servo moteur du système de saut.
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34091898_1796599387053342_4814538835645956096_n.jpg?raw=true)
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34078432_1796599843719963_6767155363545350144_n.jpg?raw=true)
# Jour 15:   
- Je termine le montage en fixant le controleur moteur, l'arduino et la plaquette sur le chassis du drone qui comprenais déjà les roues,les moteurs, et le système de saut. Enfin je découpe le ruban de leds et le fixe autour du chassis. Je fais tous les branchements entre l'arduino,la plaquette, les batteries et le controleur moteur. Le drone est monté, je le test et prend une vidéo de démonstration.
Tout fonctionne mais l'alimentation semble parfois juste car il arrive encore que l'arduino crash quand tous les moteurs et les leds fonctionne en même temps. 
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34284518_1796599490386665_5259584300340215808_n.jpg?raw=true)
![pièce](https://github.com/benjivou/Jumping-drone--Arduino/blob/master/Doc/photos/34124952_1796599420386672_5205174885835341824_n.jpg?raw=true)
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/QOd2SGuSpdc/0.jpg)](https://www.youtube.com/watch?v=QOd2SGuSpdc)





