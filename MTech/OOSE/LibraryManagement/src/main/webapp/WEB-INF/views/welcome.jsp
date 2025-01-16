<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%> <%@ taglib prefix="c"
uri="http://java.sun.com/jsp/jstl/core"%> <%@ page isELIgnored="false"%>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>Welcome</title>
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC"
      crossorigin="anonymous"
    />
    <style>
      body {
        background: linear-gradient(90deg, #ff7e5f, #feb47b);
        background-size: 400% 400%;
        animation: gradientAnimation 15s ease infinite;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        margin: 0;
        font-family: Arial, sans-serif;
      }

      .container {
        text-align: center;
        color: white;
      }

      .welcome-message {
        font-size: 2.5rem;
        font-weight: bold;
        margin-bottom: 30px;
        animation: fadeIn 2s ease-out;
      }

      .btn-welcome {
        background: linear-gradient(90deg, #ff7e5f, #feb47b);
        border: none;
        color: white;
        font-weight: bold;
        padding: 15px 30px;
        border-radius: 1rem;
        transition: background 0.3s ease;
      }

      .btn-welcome:hover {
        background: linear-gradient(90deg, #feb47b, #ff7e5f);
      }

      @keyframes gradientAnimation {
        0% {
          background-position: 0% 50%;
        }
        50% {
          background-position: 100% 50%;
        }
        100% {
          background-position: 0% 50%;
        }
      }

      @keyframes fadeIn {
        0% {
          opacity: 0;
        }
        100% {
          opacity: 1;
        }
      }
    </style>
  </head>
  <body>
    <div class="container">
      <div class="welcome-message">
        <h1>Welcome to Library Management System!</h1>
      </div>
      <a href="register" class="btn btn-welcome">Register</a>
      <a href="login" class="btn btn-welcome">Login</a>
    </div>

    <script
      src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
      integrity="sha384-MrcW6ZMFYBbZaErj6vMZkMnQJ6pajs9f/x0j2ns1ikP6JZBljMAXj0s3bGzG1wRj"
      crossorigin="anonymous"
    ></script>
  </body>
</html>
