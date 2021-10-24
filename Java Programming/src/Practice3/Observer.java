package Practice3;

public interface Observer {
    boolean addSubject(Subject subject);
    boolean deleteSubject(Subject subject);
    void update(Subject subject);
}
