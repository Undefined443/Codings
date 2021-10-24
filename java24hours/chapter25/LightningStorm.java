// A program from Chapter 25 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package org.cadenhead.minecraft;
 
import java.util.*;
import java.util.logging.*;
import org.bukkit.*;
import org.bukkit.command.*;
import org.bukkit.entity.*;
import org.bukkit.plugin.java.*;
 
public class LightningStorm extends JavaPlugin {
    public static final Logger log = Logger.getLogger("Minecraft");
    
    public boolean onCommand(CommandSender sender, Command command, 
        String label, String[] arguments) {
        
        Player me = (Player) sender;
        World world = me.getWorld();
        // get every living mob in the game
        List<LivingEntity> mobs = world.getLivingEntities();
                         
        // process lightningstorm command
        if (label.equalsIgnoreCase("lightningstorm")) { 
            if (sender instanceof Player) { 
                int myId = me.getEntityId();
                // loop through each mob one at a time
                for (LivingEntity mob : mobs) {
                    log.info("[LightningStorm]" + mob.getType());
                    // is this mob the player?
                    if (mob.getEntityId() == myId) {
                        // yes, so don't strike him
                        continue;
                    }
                    // get the mob's location
                    Location spot = mob.getLocation();
                    // lightning strike!
                    world.strikeLightning(spot);
                    // set the mob's health to 0 (dead)
                    mob.setHealth(0);
                }
            }
            return true;
        }
         
        // process mobcount command
        if (label.equalsIgnoreCase("mobcount")) {
            if (sender instanceof Player) {
                me.sendMessage("There are " + mobs.size() + " living mobs.");
                return true;
            }
        }
        return false;
    }
}