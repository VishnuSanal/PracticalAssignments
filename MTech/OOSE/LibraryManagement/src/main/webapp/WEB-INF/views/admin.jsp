<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%> <%@ taglib prefix="c"
uri="http://java.sun.com/jsp/jstl/core"%> <%@ page isELIgnored="false"%>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>Book Management System</title>
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC"
      crossorigin="anonymous"
    />
    <style>
      body {
        background-color: #f8f9fa;
      }

      .navbar-brand {
        font-weight: bold;
      }

      .card {
        margin-top: 20px;
        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
      }

      .card-header {
        background-color: #ff7e5f;
        color: white;
      }

      table th,
      table td {
        text-align: center;
        vertical-align: middle;
      }

      .btn {
        margin: 0 5px;
      }

      /* Styling the message (msg) */
      .msg-success {
        color: #28a745; /* Green color for success */
        font-weight: bold;
      }

      .msg-error {
        color: #dc3545; /* Red color for errors */
        font-weight: bold;
      }
    </style>
  </head>
  <body>
    <nav
      class="navbar navbar-expand-lg"
      style="background: linear-gradient(90deg, #ff7e5f, #feb47b)"
    >
      <div class="container-fluid">
        <a
          class="navbar-brand text-white fw-bold"
          href="#"
          style="font-size: 1.5rem"
          >🌟 New Book</a
        >
        <button
          class="navbar-toggler"
          type="button"
          data-bs-toggle="collapse"
          data-bs-target="#navbarContent"
          aria-controls="navbarContent"
          aria-expanded="false"
          aria-label="Toggle navigation"
        >
          <span class="navbar-toggler-icon" style="color: white"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarContent">
          <ul class="navbar-nav ms-auto mb-2 mb-lg-0">
            <li class="nav-item">
              <a
                class="nav-link text-white fw-bold"
                href="admin"
                style="font-size: 1.1rem"
              >
                Home
              </a>
            </li>
            <li class="nav-item">
              <a
                class="nav-link text-white fw-bold"
                href="addBook"
                style="font-size: 1.1rem"
              >
                Add Book
              </a>
            </li>

            <li class="nav-item">
              <a
                class="nav-link text-white fw-bold"
                href="login"
                style="font-size: 1.1rem"
              >
                Login
              </a>
            </li>
            <li class="nav-item">
              <a
                class="nav-link text-white fw-bold"
                href="#"
                style="font-size: 1.1rem"
              >
                About
              </a>
            </li>
            <li class="nav-item">
              <a
                class="nav-link text-white fw-bold"
                href="#"
                style="font-size: 1.1rem"
              >
                Contact
              </a>
            </li>
          </ul>
        </div>
      </div>
    </nav>

    <div class="container">
      <div class="row justify-content-center">
        <div class="col-md-10">
          <div class="card">
            <div class="card-header text-center">
              <h4>Book Details</h4>
              <!-- Display success or error message -->
              <c:if test="${not empty msg}">
                <c:choose>
                  <c:when test="${msg == 'Success'}">
                    <h5 class="msg-success">${msg}</h5>
                  </c:when>
                  <c:otherwise>
                    <h5 class="msg-error">${msg}</h5>
                  </c:otherwise>
                </c:choose>
                <c:remove var="msg" />
              </c:if>
            </div>

            <div class="card-body">
              <table class="table table-striped table-bordered">
                <thead class="table-primary">
                  <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Book Name</th>
                    <th scope="col">Author</th>
                    <th scope="col">Genre</th>
                    <th scope="col">Publisher</th>
                    <th scope="col">Language</th>
                    <th scope="col">Year Published</th>
                    <th scope="col">Available</th>
                    <th scope="col">Action</th>
                  </tr>
                </thead>
                <tbody>
                  <c:forEach var="book" items="${bookList}">
                    <tr>
                      <th scope="row">${book.id}</th>
                      <td>${book.book}</td>
                      <td>${book.author}</td>
                      <td>${book.genre}</td>
                      <td>${book.publisher}</td>
                      <td>${book.language}</td>
                      <td>${book.year}</td>
                      <td>${book.available}</td>
                      <td>
                        <a
                          href="editBook/${book.id}"
                          class="btn btn-sm btn-primary"
                          >Edit</a
                        >
                        <a
                          href="deleteBook/${book.id}"
                          class="btn btn-sm btn-danger"
                          >Delete</a
                        >
                      </td>
                    </tr>
                  </c:forEach>
                </tbody>
              </table>
            </div>
          </div>
        </div>
      </div>
    </div>

    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYBbZaErj6vMZkMnQJ6pajs9f/x0j2ns1ikP6JZBljMAXj0s3bGzG1wRj"
      crossorigin="anonymous"
    ></script>
  </body>
</html>
