// When the document is fully loaded run anonymous function()
$(document).ready(function() {
    // When button is clicked run anonymous function()
    $('.jQButton').click(function() {
        $('#colorDiv').css('background-color', this.innerHTML.toLowerCase());
    });
});