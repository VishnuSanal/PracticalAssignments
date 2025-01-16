package com.ty.controller;

import com.ty.dao.BookDao;
import com.ty.dao.UserDAO;
import com.ty.entity.Book;
import com.ty.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpSession;
import java.util.List;

@Controller
public class HomeController {

    @Autowired
    private BookDao bookDao;

    @Autowired
    private UserDAO userDAO;

    @RequestMapping(path = "/")
    public String root() {
        return "hii";

    }

    @RequestMapping(path = "/welcome")
    public String welcome() {
        return "welcome";

    }

    @RequestMapping(path = "/login")
    public String login() {
        return "login";

    }

    @RequestMapping(path = "/user")
    public String user(Model model) {
        List<Book> list = bookDao.getAllBook();
        model.addAttribute("bookList", list);
        return "user";

    }

    @RequestMapping(path = "/home")
    public String home(Model model) {
        List<Book> list = bookDao.getAllBook();
        model.addAttribute("bookList", list);

        return "home";

    }

    @RequestMapping(path = "/addBook")
    public String addBook() {
        return "add_book";

    }

    @RequestMapping(path = "/createBook", method = RequestMethod.POST)
    public String createEmp(@ModelAttribute Book book, HttpSession session) {
        book.setIsBooked(false);

        int i = bookDao.saveBook(book);
        session.setAttribute("msg", "Book Added Sucessfully");
        return "redirect:/addBook";
    }

    @RequestMapping(path = "/editBook/{id}")
    public String editEmp(@PathVariable int id, Model model) {

        Book book = bookDao.getBookById(id);
        model.addAttribute("book", book);
        return "edit_book";
    }

    @RequestMapping(path = "/issueBook/{id}")
    public String issueBook(@PathVariable int id, HttpSession session) {

        Book book = bookDao.getBookById(id);
        book.setIsBooked(true);
        bookDao.update(book);

        session.setAttribute("msg", "Book Booked Sucessfully");

        return "redirect:/user";
    }

    @RequestMapping(path = "/returnBook/{id}")
    public String returnBook(@PathVariable int id, HttpSession session) {

        Book book = bookDao.getBookById(id);
        book.setIsBooked(false);
        bookDao.update(book);

        session.setAttribute("msg", "Book Returned Sucessfully");

        return "redirect:/user";
    }

    @RequestMapping(path = "/updateBook", method = RequestMethod.POST)
    public String updateEmp(@ModelAttribute Book book, HttpSession session) {
        bookDao.update(book);
        session.setAttribute("msg", "Book Upadted Sucessfully");

        return "redirect:/home";
    }

    @RequestMapping(path = "/deleteBook/{id}")
    public String deleteEmp(@PathVariable int id, HttpSession session) {
        bookDao.delete(id);

        session.setAttribute("msg", "Book Deleted Sucessfully");

        return "redirect:/home";
    }

    @GetMapping("/register")
    public String showRegisterPage() {
        return "register";
    }

    @PostMapping("/register")
    public String register(@ModelAttribute User user, HttpSession session) {
        userDAO.register(user);
        session.setAttribute("msg", "Registration successful!");

        return "login";
    }

    @GetMapping("/login")
    public String showLoginPage() {
        return "login";
    }

    @PostMapping("/login")
    public String login(@RequestParam String username, @RequestParam String password, HttpSession session) {
        User user = userDAO.login(username, password);
        if (user != null) {
            if ("ADMIN".equals(user.getRole())) {
                return "admin";
            } else {
                return "user";
            }
        }

        session.setAttribute("msg", "Invalid credentials!");
        return "login";
    }

}
