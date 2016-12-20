import QtQuick 2.4

Item {
    width: 400
    height: 400

    Rectangle {
        id: rectangle1
        x: 40
        y: 41
        width: 318
        height: 220
        color: "#ffffff"

        Image {
            id: image1
            x: 0
            y: 0
            width: 318
            height: 220
            source: "terrain3.png"
        }
    }
}
