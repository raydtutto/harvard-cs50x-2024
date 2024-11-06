// Add scroll event listener to window
window.addEventListener('scroll', () => {
    const header = document.getElementById('mainHeader');
    // Check if the page is scrolled
    if (window.scrollY > 0) {
        header.classList.add('scrolled');
    } else {
        header.classList.remove('scrolled');
    }
});

// Form validation
(function() {
    // Prevents from using undeclared variables
    'use strict';
    window.addEventListener('load', function() {
        var forms = document.getElementsByClassName('apply-validation');
        var validation = Array.prototype.filter.call(forms, function(form) {
            // Validation
            form.addEventListener('submit', function(event) {
                event.preventDefault();
                event.stopPropagation();
                // If validation was successful
                if (form.checkValidity()) {
                    // Hide preorder modal
                    $('#preorderModal').modal('hide')
                    // Show confirm modal
                    $('#confirmModal').modal('show')
                }
                form.classList.add('was-validated');
            }, false);
        });
    }, false);
})();
