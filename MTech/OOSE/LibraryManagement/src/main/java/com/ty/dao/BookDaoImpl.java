package com.ty.dao;

import com.ty.entity.Book;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.orm.hibernate5.HibernateTemplate;
import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Repository
public class BookDaoImpl implements BookDao {

    @Autowired
    private HibernateTemplate hibernateTemplate;

    @Transactional
    @Override
    public int saveBook(Book book) {
        return (Integer) hibernateTemplate.save(book);
    }

    @Override
    public Book getBookById(int id) {
        return hibernateTemplate.get(Book.class, id);
    }

    @Override
    public List<Book> getAllBook() {
        List<Book> list = hibernateTemplate.loadAll(Book.class);
        return list;
    }

    @Transactional
    @Override
    public void update(Book book) {
        hibernateTemplate.update(book);
    }

    @Transactional
    @Override
    public void delete(int id) {
        Book book = hibernateTemplate.get(Book.class, id);
        if (book != null) {
            hibernateTemplate.delete(book);
        }
    }
}
