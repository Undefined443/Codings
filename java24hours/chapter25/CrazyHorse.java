package org.cadenhead.minecraft; 
 
import java.util.logging.*;
import org.bukkit.*;
import org.bukkit.command.*;
import org.bukkit.entity.*;
import org.bukkit.plugin.java.*;
import org.bukkit.potion.*;
 
public class CrazyHorse extends JavaPlugin { 
    public static final Logger log = Logger.getLogger("Minecraft");
   
    public boolean onCommand(CommandSender sender, Command command, 
        String label, String[] arguments) {
         
        if (label.equalsIgnoreCase("crazyhorse")) { 
            if (sender instanceof Player) { 
                Player me = (Player) sender;
                Location spot = me.getLocation();
                World world = me.getWorld();
 
                // spawn some horse-riding zombies
                int quantity = (int) (Math.random() * 10) + 1;
                log.info("[CrazyHorse] Creating " + quantity
                    + " zombies and horses");
                for (int i = 0; i < quantity; i++) {
                    // set horse and zombie location
                    Location horseSpot = new Location(world,
                        spot.getX() + (Math.random() * 15), 
                        spot.getY() + 20,
                        spot.getZ() + (Math.random() * 15));
                    Horse horse = world.spawn(horseSpot, Horse.class);
                    Zombie zombie = world.spawn(horseSpot, Zombie.class);
                    horse.setPassenger(zombie);
                    horse.setOwner(me);
                    // set the horse's color
                    int coat = (int) (Math.random() * 7);
                    switch (coat) {
                        case 0:
                            horse.setColor(Horse.Color.WHITE);
                            break;
                        case 1:
                            horse.setColor(Horse.Color.GRAY);
                            break;
                        case 2:
                            horse.setColor(Horse.Color.CREAMY);
                            break;
                        case 3:
                            horse.setColor(Horse.Color.CHESTNUT);
                            break;
                        case 4:
                            horse.setColor(Horse.Color.BROWN);
                            break;
                        case 5:
                            horse.setColor(Horse.Color.DARK_BROWN);
                            break;
                        case 6:
                            horse.setColor(Horse.Color.BLACK);
                    }
                    // increase the horse's speed
                    PotionEffect potion = new PotionEffect(
                        PotionEffectType.SPEED, 
                        Integer.MAX_VALUE, 
                        10 + (coat * 10));
                    horse.addPotionEffect(potion);
                }
                return true;
            }
        }
        return false;
    }
}
