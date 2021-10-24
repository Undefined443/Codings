// A program from Chapter 25 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package org.cadenhead.minecraft; 
  
import java.util.logging.*;
import org.bukkit.*;
import org.bukkit.command.*;
import org.bukkit.entity.*;
import org.bukkit.plugin.java.*;
  
public class SiameseCat extends JavaPlugin { 
    public static final Logger log = Logger.getLogger("Minecraft");
   
    public boolean onCommand(CommandSender sender, Command command, 
        String label, String[] arguments) {
         
        if (label.equalsIgnoreCase("siamesecat")) { 
            if (sender instanceof Player) { 
                // get the player
                Player me = (Player) sender;
                // get the player's current location
                Location spot = me.getLocation();
                // get the game world
                World world = me.getWorld();
 
                // spawn one ocelot
                Ocelot cat = world.spawn(spot, Ocelot.class);
                // make it a Siamese cat
                cat.setCatType(Ocelot.Type.SIAMESE_CAT);
                // make the player its owner
                cat.setOwner(me);
                log.info("[SiameseCat] Meow!");
                return true;
            }
        }
        return false;
    }
}