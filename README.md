# 370_FinalProject

Gill vs Zombies
created by Homero Arellano, Diego Rivera, Brandon Dale, and Sean Kozina

Click on our git hub repo link https://github.com/Xx-rat-xX/370_FinalProject
Clone the repo to your local machine via the instructions provided on canvas (See https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository )
Open your finder/file explorer and navigate to the cloned repo (should be called 'CS370_Lab06')
open the .uproject file
download starter content
close the game!! then reopen so all the assets are available/visible
shaders may take some time to finish downloading
when done, mke sure the game is being played in a seperate window (in order to see the full HUD):
  1. Where the play button is there should be 3 little pancakes (Change Play Mode and Settings)
  2. Click it, and select "New Editor Window (PIE)"

press play, and enjoy the game!

Gameplay instructions:
-BeginPlay
    -When firt opening the game you will be directed to the main menu
        -'Start" will take the player to the game and commneces the game
        -'Quit' will simply quit the game and editor
-character movement is based on WASD (with space bar to jump) and mouse/left click to aim and shoot
-Weapon inventory is based on keys '1', '2', '3', '4'
    -can only toggle the weapon if you have unlocked (via purchasing it)
    -key '1' = Pistol
    -key '2' = AK
    -key '3' = Chainsaw
    -key '4' = Sniper
- Our "interact" button is 'e' and is used to purchase perks from the candy ball machine and to purchase weapons
    - candy perk machine
        -when the player is close enough to the candy ball machine and interats with it (via 'e') a random perk is given to the player
        -POINTS REQUIRED FOR INTERACTION (1000)
        -First Perk = an increase to your health
        -Second Perk = a 20% weapon damage buff
    - Weapons/Purchase Weapons
        -you are autmoatically spawned with a pistol that holds 120 ammo and deals 10dmg
        -in the upgrade room, there are weapons hovering above pads that are obtainable via the same method as aquiring perks
        -the points required and damage for each weapon correspond as shown:
            -AK (500pts)(20dmg)
            -Chainsaw(750pts)(20dmg)
            -Sniper(1000pts)(200dmg)
        -Grenade
            -with 'g' you are able to throw a grenade that will explode on enemy impact, or after 5 seconds
 -Pickups
    -Health
        -there are 2 health pick ups with a pizza or water bottle mesh
        -when overlapping with them, if you are not at full HP, you will "obtain it" and gain 50 HP 
    -Cash
        -when overlapping with the cash mesh, you will gain 100pts
    -Ammo
        -when overlapping with the ammo you will gain ammo based on the gun you are holding and only to that gun
            -Pistol = +60 ammo
            -AK = +45 ammo
            -Sniper = +15 ammo
            -Chainsaw does not use/waste ammo
 -Enemies
    -AI Controlled with corresponding animations, detects sound to actors that contain a specifed tag
    -if player is dead will stop the zombies from moving
        -Basic Zombie
            -deals 20dmg
            -has 100hp
        -Guard Zombie
            -deals 30dmg
            -has 200hp
            -is 2x bigger than the normal zombie
            -is bound to a zone that it can patrol
  -Wave Manager
      -spawns enemies at target points locations with specific tags
      -keeps track of how many zombies are left alive and will autonomously start each round
      -increments the amount of zombies to spawn each round
  -Upgrade Room/Portal
      -when the player has killed all the zombies of that wave, a portal will spawn near the character
      -the player can interact with the portal by standing in it for 5 seconds.
      -after the 5 seconds have been met, the player is telported to an 'Upgrade Room'
      -when inside the upgrade room, the player is trapped inside until the portal turns back to its orginal
       color (from red to blue), signaling that the portal is reactivated
      -inside the upgrade room, you can find the weapons to purchase and the candyball perk machine alongside some pickups
      -when exiting the upgrade room, go inside the portal the same way you entered and you will spawn 
       exactly where you had entered from
      -after 3 seconds the portal will dissapear and the wave will have started
 -HUD
    -displays a crosshair that corresponds to where you are shooting
    -# of points and kills
    -health bar displaying player's health
    -wave number, shows you what wave you are in
    -# of ammo for the specific gun you are holding
    
 -GameOver
    -Waves will keep getting more difficult as you progress
    -When you reach 0hp/die you will be prompted with a new HUD that displays stats (kills/points)
     and with an option 'Replay' to play again
      
       
