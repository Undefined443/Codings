// A program from Chapter 25 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package org.cadenhead.minecraft; 
 
import java.util.logging.*;
import org.bukkit.*;
import org.bukkit.command.*;
import org.bukkit.entity.*;
import org.bukkit.plugin.java.*;
 
public class Cowabunga extends JavaPlugin { 
    public static final Logger log = Logger.getLogger("Minecraft");
   
    public boolean onCommand(CommandSender sender, Command command, 
        String label, String[] arguments) {
         
        if (label.equalsIgnoreCase("cowabunga")) { 
            if (sender instanceof Player) { 
                Player me = (Player) sender;
                Location spot = me.getLocation();
                World world = me.getWorld();
 
                // spawn some mushroom cows
                int quantity = (int) (Math.random() * 10) + 1;
                log.info("[Cowabunga] Creating " + quantity + " mushroom cows");
                for (int i = 0; i < quantity; i++) {
                    // set mushroom cow location
                    Location mobSpot = new Location(world,
                        spot.getX() + Math.random() * 3, 
                        spot.getY(),
                        spot.getZ() + Math.random() * 3);
                    world.spawn(mobSpot, MushroomCow.class);
                }
                return true;
            }
        }
        return false;
    }
}
