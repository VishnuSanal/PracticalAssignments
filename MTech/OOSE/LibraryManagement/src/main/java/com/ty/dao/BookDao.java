package com.ty.dao;

import com.ty.entity.Book;
import com.ty.entity.User;

import java.util.List;

public interface BookDao {

    public int saveBook(Book book);

    public Book getBookById(int id);

    public List<Book> getAllBook();

    public void update(Book book);

    public void delete(int id);
}
