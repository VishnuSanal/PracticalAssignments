package com.ty.dao;

import com.ty.entity.User;

public interface UserDAO {
    void register(User user);

    User login(String username, String password);
}