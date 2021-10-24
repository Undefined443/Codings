// A program from Chapter 25 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package org.cadenhead.minecraft;
 
import java.util.logging.*;
import org.bukkit.*;
import org.bukkit.block.*;
import org.bukkit.command.*;
import org.bukkit.entity.*;
import org.bukkit.plugin.java.*;
 
public class IceCreamScoop extends JavaPlugin {
    public static final Logger log = Logger.getLogger("Minecraft");
     
    public boolean onCommand(CommandSender sender, Command command, 
        String label, String[] arguments) {
 
        // set the default scoop radius
        double radius = 15;        
        if (arguments.length > 0) {
            try {
                // read the user-provided radius (if any)
                radius = Double.parseDouble(arguments[0]);
                // make sure it's an acceptable size (5-25)
                if ((radius < 5) | (radius > 25)) {
                    radius = 15;
                }
            } catch (NumberFormatException exception) {
                // do nothing (use the default);
            }
        }
         
        if (label.equalsIgnoreCase("icecreamscoop")) { 
            if (sender instanceof Player) { 
                scoopTerrain(sender, radius);
            }
            return true;
        }
        return false;
    }
 
    // dig a circular scoop out of the world
    private void scoopTerrain(CommandSender sender, double rad) {
        Player me = (Player) sender;
        Location spot = me.getLocation();
        World world = me.getWorld();
        
        // loop through a 3-D square with sides twice the radius width
        for (double x = spot.getX() - rad; x < spot.getX() + rad; x++) {
            for (double y = spot.getY() - rad; y < spot.getY() + rad; y++) {
                for (double z = spot.getZ() - rad; z < spot.getZ() + rad; z++) {
                    // get a location in that square
                    Location loc = new Location(world, x, y, z);
                    // see how far it is from the player
                    double xd = x - spot.getX();
                    double yd = y - spot.getY();
                    double zd = z - spot.getZ();
                    double distance = Math.sqrt(xd * xd + yd * yd + zd * zd);
                    // is it within the radius?
                    if (distance < rad) {
                        // yes, so turn that block into air
                        Block current = world.getBlockAt(loc);
                        current.setType(Material.AIR);
                    }
                }
            }
        }
       
        // play a sound after the scoop is scooped
        world.playSound(spot, Sound.BURP, 30, 5);
        log.info("[IceCreamScoop] Scooped at ("
            + spot.getX() + ","
            + spot.getY() + ","
            + spot.getZ() + ")");
    }
}
