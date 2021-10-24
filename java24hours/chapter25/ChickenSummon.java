// A program from Chapter 25 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package org.cadenhead.minecraft;
 
import java.util.*;
import java.util.logging.*;
import org.bukkit.*;
import org.bukkit.command.*;
import org.bukkit.entity.*;
import org.bukkit.plugin.java.*;
 
public class ChickenSummon extends JavaPlugin {
    public static final Logger log = Logger.getLogger("Minecraft");
    
    public boolean onCommand(CommandSender sender, Command command, 
        String label, String[] arguments) {
        
        Player me = (Player) sender;
        World world = me.getWorld();
        Location spot = me.getLocation();
        // get every living mob in the game
        List<LivingEntity> mobs = world.getLivingEntities();
                         
        // process lightningstorm command
        if (label.equalsIgnoreCase("chickensummon")) { 
            if (sender instanceof Player) { 
                int count = 0;
                // loop through each mob one at a time
                for (LivingEntity mob : mobs) {
                    // is this mob a chicken?
                    if (mob.getType() == EntityType.CHICKEN) {
                        // bring the mob to the player
                        Location chickenSpot = new Location(
                            world,
                            spot.getX() + (Math.random() * 30), 
                            spot.getY() + (Math.random() * 10),
                            spot.getZ() + (Math.random() * 30)
                        );
                        if (mob.teleport(chickenSpot)) {
                            count++;
                        }
                    }
                }
                me.sendMessage(count + " chicken summoned");  
            }
            return true;
        }
        return false;
    }
}