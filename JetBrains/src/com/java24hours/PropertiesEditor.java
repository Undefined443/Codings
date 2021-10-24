package com.java24hours;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Properties;
import java.util.Scanner;

public class PropertiesEditor {
    public static void main(String[] args) {
        File configFile = new File("config.properties");
        Properties config = new Properties();
        try (FileOutputStream ostream = new FileOutputStream(configFile, true);
        FileInputStream istream = new FileInputStream(configFile)) {
            config.load(istream);
            Label:
            while (true) {
                System.out.println("Welcome to personal property viewer");
                System.out.println("Now please choose a mode below to start:");
                System.out.println("View/Create/Edit/Delete/Quit");
                System.out.print(">");
                Scanner sc = new Scanner(System.in);
                String command = sc.nextLine();
                switch (command) {
                    case "Create": {
                        System.out.println("Please give a name to the new born:");
                        System.out.print(">");
                        String name = sc.nextLine();
                        System.out.println("Do you want to change his/her age?");
                        System.out.print("(yes/no)>");
                        if (sc.nextLine().equals("yes")) {
                            System.out.println("How old you want him/her is?");
                            System.out.print(">");
                            String age = sc.nextLine();
                            config.setProperty(name, age);
                        } else {
                            config.setProperty(name, "0");
                        }
                        System.out.println("You have created a new human!");
                        System.out.println("-------------------------------------------------");
                        break;
                    }
                    case "Edit": {
                        System.out.println("Whose profile you want to edit?");
                        System.out.print(">");
                        String name = sc.nextLine();
                        if (config.containsKey(name)) {
                            if (config.getProperty(name).equals("dead")) {
                                System.out.println("Ops, " + name + " seems dead. Fortunately you're the fucker so you can give him/her a fuck so him/she can be reborn.");
                                System.out.println("Do you want to fuck " + name + "？");
                                System.out.print("(yes/no)>");
                                if (sc.nextLine().equals("yes")) {
                                    config.setProperty(name, "0");
                                    System.out.println("Thanks to you, " + name + " has reborn. Now he/she is yours, as well as his/her pussy.");
                                } else {
                                    System.out.println(name + " remains dead.");
                                }
                            } else {
                                System.out.println(name + " founded, please enter his/her new age:");
                                System.out.print(">");
                                String age = sc.nextLine();
                                config.setProperty(name, age);
                                System.out.println("Profile edit succeed!");
                            }
                        } else {
                            System.out.println(name + "is not here.");
                        }
                        System.out.println("-------------------------------------------------");
                        break;
                    }
                    case "View":
                        config.list(System.out);
                        System.out.println("-------------------------------------------------");
                        break;
                    case "Delete": {
                        System.out.println("Who do you want to kill?");
                        System.out.print(">");
                        String name = sc.nextLine();
                        if (config.containsKey(name)) {
                            if (config.getProperty(name).equals("dead")) {
                                System.out.println(name + " is already dead. You needn't worry about him/her.");
                            } else {
                                System.out.println("You really want " + name + " die? The decision will be final.");
                                System.out.print("(yes/no)>");
                                if (sc.nextLine().equals("yes")) {
                                    config.setProperty(name, "dead");
                                    System.out.println("As you wish, " + name + " is now dead. Hope he/she deserves it.");
                                } else {
                                    System.out.println("You saved his/her ass. Now his/her ass is yours.");
                                }
                            }
                        } else {
                            System.out.println("Damn, " + name + " must have escaped!");
                        }
                        System.out.println("-------------------------------------------------");
                        break;
                    }
                    case "Quit":
                        break Label;
                    default:
                        System.out.println("You have entered a wrong order.");
                        System.out.println("-------------------------------------------------");
                        break;
                }
                config.store(ostream, "A file that controls everyone's survival.");
            }
        } catch (Exception e) {
            System.out.println("Error--" + e.getMessage());
        }
    }
}
