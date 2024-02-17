package ru.itmo.web.hw4.model;

public class Post {
    final long id;
    final long daysAgo;
    final long user_id;
    final String title;
    final String text;

    public long getId() {
        return id;
    }

    public long getUser_id() {
        return user_id;
    }

    public String getText() {
        return text;
    }

    public String getTitle() {
        return title;
    }

    public long getDaysAgo() {
        return daysAgo;
    }

    public Post(long id, long user_id, String title, String text, long daysAgo) {
        this.id = id;
        this.user_id = user_id;
        this.text = text;
        this.title = title;
        this.daysAgo = daysAgo;
    }


}
