package Practice3;

import java.io.IOException;

public interface Subject {
    boolean registerObserver(Observer observer);
    boolean removeObserver(Observer observer);
    void notifyObservers() throws IOException;
}
