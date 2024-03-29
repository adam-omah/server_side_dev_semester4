<!-- this is the re-usable header for my project, Property Rentals. -->
<header>
  <nav class="navbar navbar-expand-lg navbar-dark bg-primary">
  <div class="container-fluid">
    <a class="navbar-brand" href="index.php">Perfect Fit Rentals</a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarColor01" aria-controls="navbarColor01" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarColor01">

      <ul class="navbar-nav ml-auto">
          <li class="nav-item">
            <a class="nav-link active" href="index.php">Home
              <span class="visually-hidden">(current)</span>
            </a>
          </li>
          <li class="nav-item dropdown">
            <a class="nav-link dropdown-toggle" data-bs-toggle="dropdown" href="#" role="button" aria-haspopup="true" aria-expanded="false">Properties</a>
            <div class="dropdown-menu">
              <a class="dropdown-item" href="addProperty.php">Add Property</a>
              <a class="dropdown-item" href="rentProperty.php">Rent Property</a>
            </div>
          </li>
          <li class="nav-item dropdown">
            <a class="nav-link dropdown-toggle" data-bs-toggle="dropdown" href="#" role="button" aria-haspopup="true" aria-expanded="false">Owners</a>
            <div class="dropdown-menu">
              <a class="dropdown-item" href="addOwner.php">Add Owner</a>
              <a class="dropdown-item" href="updateOwner.php">Update Owner</a>
              <a class="dropdown-item" href="removeOwner.php">Remove Owner</a>
            </div>
          </li>
        </ul>
    </div>
  </div>
</nav>
</header>
