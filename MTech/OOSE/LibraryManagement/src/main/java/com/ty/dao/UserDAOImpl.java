package com.ty.dao;

import com.ty.entity.User;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

@Repository
public class UserDAOImpl implements UserDAO {

    @Autowired
    private SessionFactory sessionFactory;

    @Transactional
    @Override
    public void register(User user) {
        sessionFactory.getCurrentSession().save(user);
    }

    @Transactional
    @Override
    public User login(String username, String password) {
        return (User) sessionFactory.getCurrentSession()
                .createQuery("FROM User WHERE username = :username AND password = :password")
                .setParameter("username", username)
                .setParameter("password", password)
                .uniqueResult();
    }
}