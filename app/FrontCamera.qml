import QtQuick 2.0
import Ubuntu.Components 1.1
import FrontCamera 1.0
import QtMultimedia 5.0

/*!
    \brief MainView with Tabs element.
           First Tab has a single Label and
           second Tab has a single ToolbarAction.
*/

MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "frontcamera.liu-xiao-guo"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(100)
    height: units.gu(76)

    Page {
        title: i18n.tr("App with backend")

        Button {
            id: activateRearCamera
            text: "Rear Camera"

            onClicked: {
                selector. selectedCameraDevice = 0;
                camera.start();
            }
        }

        Button {
            id: activateFrontCamera
            text: "Front camera"
            anchors.left : activateRearCamera.right
            anchors.leftMargin: units.gu(2)
            onClicked: {
                selector. selectedCameraDevice = 1;
                camera.start();
            }
        }

        Camera {
            id: camera

            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

            exposure {
                exposureCompensation: -1.0
                exposureMode: Camera.ExposurePortrait
            }

            flash.mode: Camera.FlashRedEyeReduction

            imageCapture {
                onImageCaptured: {
                    photoPreview.source = preview  // Show the preview in an Image
                }
            }
        }

        CameraSelector {
            id: selector
            cameraObject: camera
        }

        VideoOutput {
            source: camera
            anchors.fill: parent
            focus : visible // to receive focus and capture key events when visible
        }

        Image {
            id: photoPreview
        }
    }
}

